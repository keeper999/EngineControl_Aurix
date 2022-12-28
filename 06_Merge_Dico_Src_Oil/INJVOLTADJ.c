/***************************************************************************
;**
;** FILE NAME      : INJVOLTADJ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INJVOLTADJ.H"
#include "INJVOLTADJ_L.H"
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
const uint32  InjSys_tiInjVoltBstReq_A[INJSYS_TIINJVOLTBSTREQ_A_COLS] = {0};
const uint8  InjSys_NrInjuBattOfsThd_A[INJSYS_NRINJUBATTOFSTHD_A_COLS] = {0};
const uint8  InjSys_stTypInjVoltBstReq_A[INJSYS_STTYPINJVOLTBSTREQ_A_COLS] = {0};
const uint8  INJVOLTADJ_u8Inhib = 0;
const uint16  InjSys_agPmpVoltAdjThd_C = 0;
const uint16  InjSys_facInjVoltBstReq_T[INJSYS_FACINJVOLTBSTREQ_T_COLS] = {0};
const uint16  InjSys_factiInjVoltBstReq_T[INJSYS_FACTIINJVOLTBSTREQ_T_COLS] = {0};
const uint16  InjSys_nInjVoltAdjThd_A[INJSYS_NINJVOLTADJTHD_A_COLS] = {0};
const uint16  InjSys_uBatMinThd_C = 0;
const uint16  InjSys_uBattInjVoltAdjThd_T[INJSYS_UBATTINJVOLTADJTHD_T_COLS] = {0};
const uint16  InjSys_uBattNrInjOfsThd_T[INJSYS_UBATTNRINJOFSTHD_T_COLS] = {0};
const uint16  InjSys_uBattPmpVoltAdjHiThd_C = 0;
const uint16  InjSys_uBattPmpVoltAdjLoThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean InjSys_bInjVoltAdj;
boolean InjSys_bPmpVoltAdj;
boolean InjSys_bVoltAdj;
boolean INJVOLTADJ_bOutputHysteresis;
uint32 InjSys_tiTotInjVoltBstReq;
uint8 InjSys_NrInjVoltBstReq;
uint16 InjSys_facInjVoltBstReq;
uint16 InjSys_tiTotPmpCmdReq;
uint16 InjSys_uBatInjVoltAdjThd;
uint16 InjSys_uBatInjVoltBstReqThd;
uint16 INJVOLTADJ_u16PFuCtlCmdReqPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

