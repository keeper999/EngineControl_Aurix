/***************************************************************************
;**
;** FILE NAME      : INJCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INJCMD.H"
#include "INJCMD_L.H"
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
const boolean  Inhibe_reactualisation_t_inj = 0;
const boolean  Manu_coupure_inj_1 = 0;
const boolean  Manu_coupure_inj_2 = 0;
const boolean  Manu_coupure_inj_3 = 0;
const boolean  Manu_coupure_inj_4 = 0;
const uint8  INJCMD_u8Inhib = 0;
const uint8  InjSys_ModeInjection_C = 0;
const uint16  InjSys_nInjPhaOfs_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
uint32 InjSys_tiInjH1LDBReqCyl1;
uint32 InjSys_tiInjH1LDBReqCyl2;
uint32 InjSys_tiInjH1LDBReqCyl3;
uint32 InjSys_tiInjH1LDBReqCyl4;
uint32 InjSys_tiInjH2LDBReqCyl1;
uint32 InjSys_tiInjH2LDBReqCyl2;
uint32 InjSys_tiInjH2LDBReqCyl3;
uint32 InjSys_tiInjH2LDBReqCyl4;
uint32 InjSys_tiInjS1LDBReqCyl1;
uint32 InjSys_tiInjS1LDBReqCyl2;
uint32 InjSys_tiInjS1LDBReqCyl3;
uint32 InjSys_tiInjS1LDBReqCyl4;
uint32 InjSys_tiInjS2LDBReqCyl1;
uint32 InjSys_tiInjS2LDBReqCyl2;
uint32 InjSys_tiInjS2LDBReqCyl3;
uint32 InjSys_tiInjS2LDBReqCyl4;
uint8 Coupure_inj_ess_appl;
uint16 InjSys_prm_agBegH1LDBReqCyl1;
uint16 InjSys_prm_agBegH1LDBReqCyl2;
uint16 InjSys_prm_agBegH1LDBReqCyl3;
uint16 InjSys_prm_agBegH1LDBReqCyl4;
uint16 InjSys_prm_agBegH2LDBReqCyl1;
uint16 InjSys_prm_agBegH2LDBReqCyl2;
uint16 InjSys_prm_agBegH2LDBReqCyl3;
uint16 InjSys_prm_agBegH2LDBReqCyl4;
uint16 InjSys_prm_agBegS1LDBReqCyl1;
uint16 InjSys_prm_agBegS1LDBReqCyl2;
uint16 InjSys_prm_agBegS1LDBReqCyl3;
uint16 InjSys_prm_agBegS1LDBReqCyl4;
uint16 InjSys_prm_agBegS2LDBReqCyl1;
uint16 InjSys_prm_agBegS2LDBReqCyl2;
uint16 InjSys_prm_agBegS2LDBReqCyl3;
uint16 InjSys_prm_agBegS2LDBReqCyl4;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

