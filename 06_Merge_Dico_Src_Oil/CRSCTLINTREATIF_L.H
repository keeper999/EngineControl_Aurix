/***************************************************************************
;**
;** FILE NAME      : CRSCTLINTREATIF_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CRSCTLINTREATIF_L_H
#define CRSCTLINTREATIF_L_H

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

extern const uint8  CRSCTLINTREATIF_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CRSCTLINTREATIF_bTimeOut;
extern boolean CRSCTLINTREATIF_Diag_onPrev;
extern uint16 CRSCTLINTREATIF_u16Timer;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CRSCTLINTREATIF_vid3ADTreatIf(void);
void CRSCTLINTREATIF_vid44DTreatIf(void);
void CRSCTLINTREATIF_vid50DTreatIf(void);
void CRSCTLINTREATIF_vidAuth_clc(void);
void CRSCTLINTREATIF_vidCrsctl(void);
void CRSCTLINTREATIF_vidCrsCtl_Can(void);
void CRSCTLINTREATIF_vidInit(void);
void CRSCTLINTREATIF_vidInitOutput(void);
void CRSCTLINTREATIF_vidOutClunGearEg(void);


#endif /* CRSCTLINTREATIF_L_H */

/*-------------------------------- end of file -------------------------------*/
