/***************************************************************************
;**
;** FILE NAME      : ACPRESACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACPRESACQ_L_H
#define ACPRESACQ_L_H

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

extern const uint8  ACPRESACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ACPRESACQ_bFilteringInit;
extern boolean Ext_bDgoGrd_pACMes;
extern boolean Ext_bDgoHi_pACMes;
extern boolean Ext_bDgoLo_pACMes;
extern boolean Ext_bMonRunGrd_pACMes;
extern boolean Ext_bMonRunGrdSng_pACMes;
extern boolean Ext_bMonRunHi_pACMes;
extern boolean Ext_bMonRunLo_pACMes;
extern uint8 Cl_pressure_diag_trk_count;
extern uint16 Ac_cooling_pressure_trk_delta;
extern uint16 Cl_current_pressure;
extern uint16 Cl_pressure_result_ratio;
extern uint16 Cl_raw_pressure_prec;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACPRESACQ_vidDiagnosisConversion(void);
void ACPRESACQ_vidElectricDiagnosis(void);
void ACPRESACQ_vidFiltering(void);
void ACPRESACQ_vidFunctionalDetection(void);
void ACPRESACQ_vidInit(void);
void ACPRESACQ_vidInitOutput(void);
void ACPRESACQ_vidMgtDefaultTracking(void);
void ACPRESACQ_VidPressRefriDiagFunc(void);
void ACPRESACQ_vidPressure_refri(void);


#endif /* ACPRESACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
