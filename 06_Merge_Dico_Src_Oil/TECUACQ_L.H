/***************************************************************************
;**
;** FILE NAME      : TECUACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TECUACQ_L_H
#define TECUACQ_L_H

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

extern const uint8  TECUACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean SenAct_bDgoScg_tECUAcq;
extern boolean SenAct_bDgoScp_tECUAcq;
extern boolean SenAct_bMonRunScg_tECUAcq;
extern boolean SenAct_bMonRunScp_tECUAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TECUACQ_vidAcquisition(void);
void TECUACQ_vidDiagnosis(void);
void TECUACQ_vidElectrical_Diagnosis(void);
void TECUACQ_vidInit(void);


#endif /* TECUACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
