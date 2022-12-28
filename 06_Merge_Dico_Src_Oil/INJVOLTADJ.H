/***************************************************************************
;**
;** FILE NAME      : INJVOLTADJ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJVOLTADJ_H
#define INJVOLTADJ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define INJSYS_FACINJVOLTBSTREQ_T_COLS         ( 4 )
#define INJSYS_FACTIINJVOLTBSTREQ_T_COLS       ( 9 )
#define INJSYS_NINJVOLTADJTHD_A_COLS           ( 9 )
#define INJSYS_NRINJUBATTOFSTHD_A_COLS         ( 4 )
#define INJSYS_STTYPINJVOLTBSTREQ_A_COLS       ( 4 )
#define INJSYS_TIINJVOLTBSTREQ_A_COLS          ( 9 )
#define INJSYS_UBATTINJVOLTADJTHD_T_COLS       ( 9 )
#define INJSYS_UBATTNRINJOFSTHD_T_COLS         ( 4 )

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

extern const uint32  InjSys_tiInjVoltBstReq_A[INJSYS_TIINJVOLTBSTREQ_A_COLS];
extern const uint8  InjSys_NrInjuBattOfsThd_A[INJSYS_NRINJUBATTOFSTHD_A_COLS];
extern const uint8  InjSys_stTypInjVoltBstReq_A[INJSYS_STTYPINJVOLTBSTREQ_A_COLS];
extern const uint16  InjSys_agPmpVoltAdjThd_C;
extern const uint16  InjSys_facInjVoltBstReq_T[INJSYS_FACINJVOLTBSTREQ_T_COLS];
extern const uint16  InjSys_factiInjVoltBstReq_T[INJSYS_FACTIINJVOLTBSTREQ_T_COLS];
extern const uint16  InjSys_nInjVoltAdjThd_A[INJSYS_NINJVOLTADJTHD_A_COLS];
extern const uint16  InjSys_uBatMinThd_C;
extern const uint16  InjSys_uBattInjVoltAdjThd_T[INJSYS_UBATTINJVOLTADJTHD_T_COLS];
extern const uint16  InjSys_uBattNrInjOfsThd_T[INJSYS_UBATTNRINJOFSTHD_T_COLS];
extern const uint16  InjSys_uBattPmpVoltAdjHiThd_C;
extern const uint16  InjSys_uBattPmpVoltAdjLoThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean InjSys_bVoltAdj;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJVOLTADJ_vidEntryInit(void);
void Volt_EveInj_InjVoltAdj(void);
void Volt_EveSpl_InjVoltAdj(void);


#endif /* INJVOLTADJ_H */

/*-------------------------------- end of file -------------------------------*/
