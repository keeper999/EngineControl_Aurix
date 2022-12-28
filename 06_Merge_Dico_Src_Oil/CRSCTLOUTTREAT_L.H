/***************************************************************************
;**
;** FILE NAME      : CRSCTLOUTTREAT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CRSCTLOUTTREAT_L_H
#define CRSCTLOUTTREAT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CRSCTLOUTTREAT_I.h"
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

extern const uint8  CRSCTLOUTTREAT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CrsCtl_bDgoCrsCtlDft;
extern boolean CrsCtl_bMonRunCrsCtlDft;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CRSCTLOUTTREAT_vidFctTreatProc(void);
void CRSCTLOUTTREAT_vidInitOutput(void);
void CRSCTLOUTTREAT_vidSubSystem(void);
void CRSCTLOUTTREAT_vidxVV_init(void);
void CRSCTLOUTTREAT_vidxVVFail(void);
void CRSCTLOUTTREAT_vidxVVFailCond(void);
void CRSCTLOUTTREAT_vidxVVInFctTreat(void);
void CRSCTLOUTTREAT_vidxVVStateIndic(void);
void CRSCTLOUTTREAT_vidxVVStIndiCond(void);


#endif /* CRSCTLOUTTREAT_L_H */

/*-------------------------------- end of file -------------------------------*/
