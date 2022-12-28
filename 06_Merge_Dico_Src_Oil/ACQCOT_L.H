/***************************************************************************
;**
;** FILE NAME      : ACQCOT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQCOT_L_H
#define ACQCOT_L_H

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

extern const uint8  ACQCOT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ACQCOT_bExtbDgoOctCoMesPrev;
extern boolean ACQCOT_bExtbDgoScgtCoMesPrev;
extern boolean ACQCOT_bExtbDgoScptCoMesPrev;
extern boolean Autorise_diag_grad;
extern boolean Ext_bDgoGrd_tCoMes;
extern boolean Ext_bDgoOc_tCoMes;
extern boolean Ext_bDgoScg_tCoMes;
extern boolean Ext_bDgoScp_tCoMes;
extern boolean Ext_bMonRunGrd_tCoMes;
extern boolean Ext_bMonRunOc_tCoMes;
extern boolean Ext_bMonRunScg_tCoMes;
extern boolean Ext_bMonRunScp_tCoMes;
extern uint8 ACQCOT_u8TempEauMesureePrev;
extern uint8 Temperature_eau_mesuree_delta;
extern uint16 Temp_eau_diag_grad_count;
extern uint16 Temperature_eau_precise;
extern uint16 Temperature_eau_precise_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACQCOT_vidCrTRunWaterTemp(void);
void ACQCOT_vidElecFailureDetection(void);
void ACQCOT_vidGradientTest(void);
void ACQCOT_vidGradientTestParameters(void);
void ACQCOT_vidInitialization(void);
void ACQCOT_vidInitTemperature(void);
void ACQCOT_vidRunWaterTemp(void);
void ACQCOT_vidStallWaterTemp(void);
void ACQCOT_vidStoragetCoPwrl(void);
void ACQCOT_vidTreatment(void);
void ACQCOT_vidWaterCalTemp(void);
void ACQCOT_vidWaterFailure(void);
void ACQCOT_vidWaterTempAcquisition(void);
void ACQCOT_vidWaterTempTreatment(void);


#endif /* ACQCOT_L_H */

/*-------------------------------- end of file -------------------------------*/
