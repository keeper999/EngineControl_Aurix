/***************************************************************************
;**
;** FILE NAME      : CLUPEDPOSNDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CLUPEDPOSNDIAG_L_H
#define CLUPEDPOSNDIAG_L_H

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

extern const uint8  CLUPEDPOSNDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CLUPEDPOSNDIAG_bBasculeRSOutInv;
extern boolean CLUPEDPOSNDIAG_bBasculeRSOutput;
extern boolean CLUPEDPOSNDIAG_bCluBasculeRSOut;
extern boolean CLUPEDPOSNDIAG_bCondIncDecCnt;
extern boolean CLUPEDPOSNDIAG_bDrvCycDiagCluPrv;
extern boolean CLUPEDPOSNDIAG_bEnaCounter_Prev;
extern boolean CLUPEDPOSNDIAG_bRstCntDiaCluPrev;
extern boolean StaCtl_bCluPDrvCycDfct;
extern boolean StaCtl_bCluPMainDfct;
extern boolean StaCtl_bDrvCycDiagCluP;
extern uint32 CLUPEDPOSNDIAG_u32CounterOutput;
extern uint8 CLUPEDPOSNDIAG_u8CoPTStEngPrev;
extern uint8 CLUPEDPOSNDIAG_u8GearRatioPrev;
extern uint8 CLUPEDPOSNDIAG_u8ResteCounter;
extern sint16 CLUPEDPOSNDIAG_s16ExtCoMes;
extern uint16 CLUPEDPOSNDIAG_u16CounterOutput;
extern uint16 CLUPEDPOSNDIAG_u16Ext_PHiFreqSwt;
extern uint16 CLUPEDPOSNDIAG_u16VehSpdVeh;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CLUPEDPOSNDIAG_vidActiv_diag(void);
void CLUPEDPOSNDIAG_vidCompteur(void);
void CLUPEDPOSNDIAG_vidCondIncDecCnt(void);
void CLUPEDPOSNDIAG_vidCycle_de_tests(void);
void CLUPEDPOSNDIAG_vidDetect_dysfcts(void);
void CLUPEDPOSNDIAG_vidDetectionMvt(void);
void CLUPEDPOSNDIAG_vidInitOutput(void);


#endif /* CLUPEDPOSNDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
