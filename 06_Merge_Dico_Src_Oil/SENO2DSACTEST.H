/***************************************************************************
;**
;** FILE NAME      : SENO2DSACTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SENO2DSACTEST_H
#define SENO2DSACTEST_H

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

extern const uint32  ActrTstSO2_DsTempo_C;
extern const uint32  ActrTstSO2Ds_TotTime;
extern const uint16  ActrTstSO2Ds_OffTime;
extern const uint16  ActrTstSO2Ds_OnTime;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean HeatSenO2_bDsPwrRlyCmd;
extern boolean HeatSenO2_bDsTstCmd;
extern boolean HeatSenO2_bDsTstCmpl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_EveRst_ActrTSO2Ds(void);
void HeatSenO2_SdlFast_ActrTSO2Ds(void);


#endif /* SENO2DSACTEST_H */

/*-------------------------------- end of file -------------------------------*/
