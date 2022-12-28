/***************************************************************************
;**
;** FILE NAME      : VEHST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHST_L_H
#define VEHST_L_H

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

extern const uint8  VEHST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Crank_to_run_engine_rpm_high;
extern uint8 Crank_to_run_engine_rpm_low;
extern uint8 Demarrage_en_cours_counter;
extern uint16 Initial_vs_crank_tdc_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VEHST_vidCompThr(void);
void VEHST_vidInitStart(void);
void VEHST_vidManageEngineCranking(void);
void VEHST_vidManageEngineRunning(void);
void VEHST_vidManageEngineStalled(void);
void VEHST_vidStartCondition(void);
void VEHST_vidVehStateControl(void);


#endif /* VEHST_L_H */

/*-------------------------------- end of file -------------------------------*/
