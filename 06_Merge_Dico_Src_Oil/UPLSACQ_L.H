/***************************************************************************
;**
;** FILE NAME      : UPLSACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef UPLSACQ_L_H
#define UPLSACQ_L_H

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

extern const uint8  UPLSACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoOc_uUpLs;
extern boolean Ext_bDgoScg_uUpLs;
extern boolean Ext_bDgoScp_uUpLs;
extern boolean Ext_bMonRunOc_uUpLs;
extern boolean Ext_bMonRunScg_uUpLs;
extern boolean Ext_bMonRunScp_uUpLs;
extern boolean Ext_bMonWaitOc_uUpLs;
extern boolean Ext_bMonWaitScg_uUpLs;
extern boolean Ext_bMonWaitScp_uUpLs;
extern boolean Panne_so2_am_presente;
extern boolean Tension_so2_am_first_computed;
extern boolean UPLSACQ_bFiltSondeEnablePrev;
extern uint32 UPLSACQ_u32FiltredVoltageMem;
extern uint16 Ldsen_active_dead_zone_count;
extern uint16 Ldsen_confirm_def_so2_am_count;
extern uint16 Ldsen_gas_course_so2_am_count;
extern uint16 Ldsen_sensor_dead_zone_count;
extern uint16 Tension_sonde_am_max_dc;
extern uint16 Tension_sonde_am_min_dc;
extern uint16 UPLSACQ_u16SenO2UsFiltred;
extern uint16 UPLSACQ_u16SenO2UsVoltagePrev1;
extern uint16 UPLSACQ_u16SenO2UsVoltagePrev2;
extern uint16 UPLSACQ_u16SenO2UsVoltagePrev3;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void UPLSACQ_vidExtremeSenO2VoltMngt(void);
void UPLSACQ_vidFilteringStallEngine(void);
void UPLSACQ_vidFilteringSyncEngine(void);
void UPLSACQ_vidInitDeadZoneCount(void);
void UPLSACQ_vidInitOutput(void);
void UPLSACQ_vidLeanToRichSensor(void);
void UPLSACQ_vidNoFaultSenO2VoltMngt(void);
void UPLSACQ_vidRichToLeanSensor(void);
void UPLSACQ_vidRunKeyOff(void);
void UPLSACQ_vidSenO2StateKeyOff(void);
void UPLSACQ_vidSenO2UsAcquiTreatment(void);
void UPLSACQ_vidSenO2UsCounterInhib(void);
void UPLSACQ_vidSenO2UsCountInhibInit(void);
void UPLSACQ_vidSenO2UsDefault(void);
void UPLSACQ_vidSenO2UsDefaultMngt(void);
void UPLSACQ_vidSenO2UsDiagGroundMngt(void);
void UPLSACQ_vidSenO2UsFiltStallEng(void);
void UPLSACQ_vidSenO2UsFiltSyncEngine(void);
void UPLSACQ_vidSenO2UsFreeze(void);
void UPLSACQ_vidSenO2UsInitialization(void);
void UPLSACQ_vidSenO2UsManagement(void);
void UPLSACQ_vidSenO2UsVoltageCalc(void);
void UPLSACQ_vidSO2UsDefaultCountDec(void);


#endif /* UPLSACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
