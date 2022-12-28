/***************************************************************************
;**
;** FILE NAME      : ACQDGOHAL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQDGOHAL_L_H
#define ACQDGOHAL_L_H

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

extern const uint8  ACQDGOHAL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACQDGOHAL_vidCmdDiagAuthStrtSTT(void);
void ACQDGOHAL_vidCmdDiagBlowBy1(void);
void ACQDGOHAL_vidCmdDiagBlowBy2(void);
void ACQDGOHAL_vidCmdDiagCstr(void);
void ACQDGOHAL_vidCmdDiagDmtr(void);
void ACQDGOHAL_vidCmdDiagDrvO2Ds(void);
void ACQDGOHAL_vidCmdDiagDrvO2Us(void);
void ACQDGOHAL_vidCmdDiagECTReq(void);
void ACQDGOHAL_vidCmdDiagEngStOutIdc(void);
void ACQDGOHAL_vidCmdDiagGMV1GMV2(void);
void ACQDGOHAL_vidCmdDiagPropFuPmp(void);
void ACQDGOHAL_vidCmdDiagRly(void);
void ACQDGOHAL_vidCmdDiagStrtr(void);
void ACQDGOHAL_vidCmdDiagThrOverload(void);
void ACQDGOHAL_vidCmdDiagVlvActEx(void);
void ACQDGOHAL_vidCmdDiagVlvActIn(void);
void ACQDGOHAL_vidInit_OutPutCmdDiag(void);


#endif /* ACQDGOHAL_L_H */

/*-------------------------------- end of file -------------------------------*/
