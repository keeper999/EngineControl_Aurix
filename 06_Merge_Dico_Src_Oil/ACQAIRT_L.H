/***************************************************************************
;**
;** FILE NAME      : ACQAIRT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQAIRT_L_H
#define ACQAIRT_L_H

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

extern const uint8  ACQAIRT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ACQAIRT_bExtbDgoOctAirMesPrev;
extern boolean ACQAIRT_bExtbDgoScgtAirMesPrev;
extern boolean ACQAIRT_bExtbDgoScptAirMesPrev;
extern boolean Autorise_diag_grad_air;
extern boolean Ext_bDgoGrd_tAirMes;
extern boolean Ext_bDgoOc_tAirMes;
extern boolean Ext_bDgoScg_tAirMes;
extern boolean Ext_bDgoScp_tAirMes;
extern boolean Ext_bMonRunGrd_tAirMes;
extern boolean Ext_bMonRunOc_tAirMes;
extern boolean Ext_bMonRunScg_tAirMes;
extern boolean Ext_bMonRunScp_tAirMes;
extern uint8 Temp_air_diag_grad_count;
extern uint8 Temperature_air_mesuree_delta;
extern uint8 Temperature_air_mesuree_prev;
extern uint16 Tair_raw_range_voltage;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACQAIRT_vidAirTemperatureAcqui(void);
void ACQAIRT_vidAirTemperatureMeas(void);
void ACQAIRT_vidElectricFailDetection(void);
void ACQAIRT_vidFunctionalDiagnosis(void);
void ACQAIRT_vidGradientTest(void);
void ACQAIRT_vidGradientTestParams(void);
void ACQAIRT_vidInitOutput(void);
void ACQAIRT_vidResetAirIntakeTemp(void);
void ACQAIRT_vidThrMesTempAir(void);


#endif /* ACQAIRT_L_H */

/*-------------------------------- end of file -------------------------------*/
