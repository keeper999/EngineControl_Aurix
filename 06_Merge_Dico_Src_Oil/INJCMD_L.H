/***************************************************************************
;**
;** FILE NAME      : INJCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJCMD_L_H
#define INJCMD_L_H

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

extern const uint8  INJCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern uint32 InjSys_tiInjH1LDBReqCyl1;
extern uint32 InjSys_tiInjH1LDBReqCyl2;
extern uint32 InjSys_tiInjH1LDBReqCyl3;
extern uint32 InjSys_tiInjH1LDBReqCyl4;
extern uint32 InjSys_tiInjH2LDBReqCyl1;
extern uint32 InjSys_tiInjH2LDBReqCyl2;
extern uint32 InjSys_tiInjH2LDBReqCyl3;
extern uint32 InjSys_tiInjH2LDBReqCyl4;
extern uint32 InjSys_tiInjS1LDBReqCyl1;
extern uint32 InjSys_tiInjS1LDBReqCyl2;
extern uint32 InjSys_tiInjS1LDBReqCyl3;
extern uint32 InjSys_tiInjS1LDBReqCyl4;
extern uint32 InjSys_tiInjS2LDBReqCyl1;
extern uint32 InjSys_tiInjS2LDBReqCyl2;
extern uint32 InjSys_tiInjS2LDBReqCyl3;
extern uint32 InjSys_tiInjS2LDBReqCyl4;
extern uint8 Coupure_inj_ess_appl;
extern uint16 InjSys_prm_agBegH1LDBReqCyl1;
extern uint16 InjSys_prm_agBegH1LDBReqCyl2;
extern uint16 InjSys_prm_agBegH1LDBReqCyl3;
extern uint16 InjSys_prm_agBegH1LDBReqCyl4;
extern uint16 InjSys_prm_agBegH2LDBReqCyl1;
extern uint16 InjSys_prm_agBegH2LDBReqCyl2;
extern uint16 InjSys_prm_agBegH2LDBReqCyl3;
extern uint16 InjSys_prm_agBegH2LDBReqCyl4;
extern uint16 InjSys_prm_agBegS1LDBReqCyl1;
extern uint16 InjSys_prm_agBegS1LDBReqCyl2;
extern uint16 InjSys_prm_agBegS1LDBReqCyl3;
extern uint16 InjSys_prm_agBegS1LDBReqCyl4;
extern uint16 InjSys_prm_agBegS2LDBReqCyl1;
extern uint16 InjSys_prm_agBegS2LDBReqCyl2;
extern uint16 InjSys_prm_agBegS2LDBReqCyl3;
extern uint16 InjSys_prm_agBegS2LDBReqCyl4;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJCMD_vidDiagnosticInjecteur1(void);
void INJCMD_vidDiagnosticInjecteur2(void);
void INJCMD_vidDiagnosticInjecteur3(void);
void INJCMD_vidDiagnosticInjecteur4(void);
void INJCMD_vidDisableDriver(void);
void INJCMD_vidInhibitAllCylinder(void);
void INJCMD_vidInitDiag(void);
void INJCMD_vidInitEnable(void);
void INJCMD_vidInitialisationMode(void);
void INJCMD_vidInitOutput(void);
void INJCMD_vidInjectorsDiagnostic(void);
void INJCMD_vidInjHALCmdProfile(void);
void INJCMD_vidInjHALUpdate(void);
void INJCMD_vidManCutByCylinder(void);
void INJCMD_vidManInjTime(void);
void INJCMD_vidModeInjectionSequentielleCyl1(void);
void INJCMD_vidModeInjectionSequentielleCyl2(void);
void INJCMD_vidModeInjectionSequentielleCyl3(void);
void INJCMD_vidModeInjectionSequentielleCyl4(void);
void INJCMD_vidUpdate(void);
uint32 INJCMD_vidFormatInjTime(uint32 uint32_tiInjReqCyl);


#endif /* INJCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
