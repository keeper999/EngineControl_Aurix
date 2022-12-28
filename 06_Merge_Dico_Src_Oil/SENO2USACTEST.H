/***************************************************************************
;**
;** FILE NAME      : SENO2USACTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SENO2USACTEST_H
#define SENO2USACTEST_H

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

extern const uint32  ActrTstSO2_UsTempo_C;
extern const uint32  ActrTstSO2Us_TotTime;
extern const uint16  ActrTstSO2Us_OffTime;
extern const uint16  ActrTstSO2Us_OnTime;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean HeatSenO2_bUsPwrRlyCmd;
extern boolean HeatSenO2_bUsTstCmd;
extern boolean HeatSenO2_bUsTstCmpl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_EveRst_ActrTSO2Us(void);
void HeatSenO2_SdlFast_ActrTSO2Us(void);


#endif /* SENO2USACTEST_H */

/*-------------------------------- end of file -------------------------------*/
