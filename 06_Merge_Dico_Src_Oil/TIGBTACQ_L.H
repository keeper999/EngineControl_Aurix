/***************************************************************************
;**
;** FILE NAME      : TIGBTACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TIGBTACQ_L_H
#define TIGBTACQ_L_H

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

extern const uint8  TIGBTACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean SenAct_bDgoScg_tIGBTAcq;
extern boolean SenAct_bDgoScp_tIGBTAcq;
extern boolean SenAct_bMonRunScg_tIGBTAcq;
extern boolean SenAct_bMonRunScp_tIGBTAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TIGBTACQ_vidAcquisition(void);
void TIGBTACQ_vidDiagnosis(void);
void TIGBTACQ_vidElectrical_Diagnosis(void);
void TIGBTACQ_vidInit(void);


#endif /* TIGBTACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
