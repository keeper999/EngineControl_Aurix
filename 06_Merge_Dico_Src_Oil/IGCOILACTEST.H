/***************************************************************************
;**
;** FILE NAME      : IGCOILACTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGCOILACTEST_H
#define IGCOILACTEST_H

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

extern const uint8  ActrTstCoil_OnTime;
extern const uint16  ActrTstCoil_OffTime;
extern const uint16  ActrTstCoil_TempoIdle_C;
extern const uint16  ActrTstCoil_TotTime;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IgCmd_bCoil1TstCmpl;
extern boolean IgCmd_bCoil2TstCmpl;
extern boolean IgCmd_bCoil3TstCmpl;
extern boolean IgCmd_bCoil4TstCmpl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgCmd_EveRst_ActrTstCoil(void);
void IgCmd_SdlFast_ActrTstCoil(void);


#endif /* IGCOILACTEST_H */

/*-------------------------------- end of file -------------------------------*/
